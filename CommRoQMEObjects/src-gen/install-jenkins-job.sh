#!/bin/bash

CONFIGFILE=/tmp/jenkins-job-install-tmp.xml
cp jenkins-job-config.xml $CONFIGFILE

cd ..
SUBVERSIONPATH=`svn info | grep '^URL'| awk '{print $NF}'`

echo "======================================="
echo "INSTALL CommObject as jenkins job"
echo "======================================="

echo "Check the following INSTALL configurations:"

read -p "Enter ACE_ROOT [$ACE_ROOT]:" USER_ACE_ROOT
USER_ACE_ROOT=${USER_ACE_ROOT:-$ACE_ROOT}

read -p "Enter default SMART_ROOT_ACE [$SMART_ROOT_ACE]:" USER_SMART_ROOT_ACE
USER_SMART_ROOT_ACE=${USER_SMART_ROOT_ACE:-$SMART_ROOT_ACE}

read -p "Enter default SVN repo url $SUBVERSIONPATH" USER_SUBVERSIONPATH
USER_SUBVERSIONPATH=${USER_SUBVERSIONPATH:-$SUBVERSIONPATH}


sed -i "s|@SMART_ROOT_ACE@|$USER_SMART_ROOT_ACE|g" $CONFIGFILE
sed -i "s|@ACE_ROOT@|$USER_ACE_ROOT|g" $CONFIGFILE
sed -i "s|@SVN-REPRO_PATH@|$USER_SUBVERSIONPATH|g" $CONFIGFILE

wget http://localhost:8080/jnlpJars/jenkins-cli.jar -O /tmp/jenkins-cli.jar

echo "======================================="
echo "check if job is already there ..."
echo "======================================="
GETJOB=`java -jar /tmp/jenkins-cli.jar -s http://localhost:8080/ get-job "CommRoQMEObjects" 2>&1`
echo "get-job CommRoQMEObjects: $GETJOB"
echo "======================================="

if [[ $GETJOB == *"No such job"* ]]
then
	echo "======================================="
	echo "JOB NOT FOUND --> create job"
	echo "======================================="
	java -jar /tmp/jenkins-cli.jar -s http://localhost:8080/ create-job "CommRoQMEObjects" < $CONFIGFILE
else
	echo "======================================="
	echo "JOB FOUND --> update job"
	echo "======================================="
	java -jar /tmp/jenkins-cli.jar -s http://localhost:8080/ update-job "CommRoQMEObjects" < $CONFIGFILE
fi


echo "======================================="
echo "DONE"
echo "======================================="
exit 0
