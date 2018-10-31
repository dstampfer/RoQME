#!/bin/bash

CONFIGFILE=/tmp/jenkins-job-install-tmp.xml

cd ..

##########################
# CHECK IF INSIDE GIT OR SVN
	
################
# SVN
#SUBVERSIONPATH=`svn info | grep '^URL'| awk '{print $NF}'`
SUBVERSIONPATH=`svn info ${WCDIR} 2> /dev/null | grep "^URL:" | cut -d" " -f2`
	
	
if [ -z "${SUBVERSIONPATH}" ]
 then
   echo "SVN: NOT part of a SVN working copy."
   ISINSVNREPO=false
 else 
   ISINSVNREPO=true
   echo "SVN: part of a SVN working copy."
   cp src-gen/jenkins-job-config-svn.xml $CONFIGFILE
fi
	
################
# GIT
ISINGITREPO=`git rev-parse --is-inside-work-tree`
echo ${ISINGITREPO}
if [ "${ISINGITREPO}" = true ]
 then
   echo "GIT: part of a GIT workspace copy."
   ISINGITREPO=true
   GITREPOPATH=`git config --get remote.origin.url`
   GITPREFIXPATH=`git rev-parse --show-prefix`
   cp src-gen/jenkins-job-config-git.xml $CONFIGFILE
 else 
   ISINGITREPO=false
   echo "GIT: NOT part of a GIT workspace copy."
fi

if [ "${ISINGITREPO}" = false ] && [ "${ISINSVNREPO}" = false ]
 then
   echo "ERROR: Not part of a GIT or SVN repo."
   exit 1
fi
	
##########################
	
echo "======================================="
echo "INSTALL Component as jenkins job"
echo "======================================="

echo "Check the following INSTALL configurations:"

read -p "Enter ACE_ROOT [$ACE_ROOT]:" USER_ACE_ROOT
USER_ACE_ROOT=${USER_ACE_ROOT:-$ACE_ROOT}

read -p "Enter default SMART_ROOT_ACE [$SMART_ROOT_ACE]:" USER_SMART_ROOT_ACE
USER_SMART_ROOT_ACE=${USER_SMART_ROOT_ACE:-$SMART_ROOT_ACE}

sed -i "s|@SMART_ROOT_ACE@|$USER_SMART_ROOT_ACE|g" $CONFIGFILE
sed -i "s|@ACE_ROOT@|$USER_ACE_ROOT|g" $CONFIGFILE


##########################
# SVN
if [ "${ISINSVNREPO}" = true ]
 then
  read -p "Enter default SVN repo url $SUBVERSIONPATH" USER_SUBVERSIONPATH
  USER_SUBVERSIONPATH=${USER_SUBVERSIONPATH:-$SUBVERSIONPATH}

  sed -i "s|@SVN-REPRO_PATH@|$USER_SUBVERSIONPATH|g" $CONFIGFILE
fi

##########################
# GIT
if [ "${ISINGITREPO}" = true ]
 then
  read -p "Enter default GIT repo url $GITREPOPATH" USER_GITREPOPATH
  USER_GITREPOPATH=${USER_GITREPOPATH:-$GITREPOPATH}

  sed -i "s|@GIT-REPO-PATH@|$GITREPOPATH|g" $CONFIGFILE
  sed -i "s|@GIT-PREFIX-PATH@|$GITPREFIXPATH|g" $CONFIGFILE
fi

wget http://localhost:8080/jnlpJars/jenkins-cli.jar -O /tmp/jenkins-cli.jar

echo "======================================="
echo "check if job is already there ..."
echo "======================================="
GETJOB=`java -jar /tmp/jenkins-cli.jar -s http://localhost:8080/ get-job "SmartRoQMEMetricsProvider" 2>&1`
echo "get-job SmartRoQMEMetricsProvider: $GETJOB"
echo "======================================="

if [[ $GETJOB == *"No such job"* ]]
then
	echo "======================================="
	echo "JOB NOT FOUND --> create job"
	echo "======================================="
	java -jar /tmp/jenkins-cli.jar -s http://localhost:8080/ create-job "SmartRoQMEMetricsProvider" < $CONFIGFILE
else
	echo "======================================="
	echo "JOB FOUND --> update job"
	echo "======================================="
	java -jar /tmp/jenkins-cli.jar -s http://localhost:8080/ update-job "SmartRoQMEMetricsProvider" < $CONFIGFILE
fi


echo "======================================="
echo "DONE"
echo "======================================="
exit 0
