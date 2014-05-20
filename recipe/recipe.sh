#!/usr/bin/env bash

# Install dependencies for the FinalStateAnalysis package.
# Usage:
#   OPT1=0 OPT2=1 ./recipe.sh
#
# Some packages are optional.   The options are passed as environment variables 
# to the script (0 or 1) Here are the following options:
# 
#    PATPROD: enable PAT tuple production
#    LIMIT: code for computing limits
#    LUMI: code for computing instantaneous luminosity (lumiCalc and friends)
#    MVAMET: code for MVA MET.  Always produced if PATPROD=1
#    HZZ: MELA and HZZAngles to support the ZZ analysis. Always produced if PATPROD=1
#
# Options which are absolutely required, like PAT data formats, are always 
# installed.
#
# Author: Bucky Badger and friends, UW Madison

# Set default values for the options
LIMITS=${LIMITS:-0}
LUMI=${LUMI:-1}
PATPROD=${PATPROD:-1}
MVAMET=${MVAMET:-$PATPROD}
HZZ=${HZZ:-0}

set -o errexit
set -o nounset

: ${CMSSW_BASE:?"CMSSW_BASE is not set!  Run cmsenv before recipe.sh"}

# Check CMSSW version
MAJOR_VERSION=`echo $CMSSW_VERSION | sed "s|CMSSW_\([0-9]\)_.*|\1|"`
MINOR_VERSION=`echo $CMSSW_VERSION | sed "s|CMSSW_\([0-9]\)_\([0-9]\)_.*|\2|"`

echo "Detected CMSSW version: $MAJOR_VERSION $MINOR_VERSION"

echo "Checking for CERN CVS kerberos ticket"
set +o errexit
HAS_TICKET=`klist 2>&1 | grep CERN.CH`
# Check if we can checkout anonymously
IS_ANON=`echo $CVSROOT | grep pserver`
set -o errexit

if [ -z "$HAS_TICKET" ]; then
  if [ -z "$IS_ANON" ]; then
    echo "ERROR: You need to kinit yourname@CERN.CH to enable CVS checkouts"
    exit 1
  fi
fi

echo "Store your git ssh password"
eval `ssh-agent -s` 
ssh-add

echo "I'm going to install the FinalStateAnalysis with the following options:"
echo " Limit setting (\$LIMITS): $LIMITS"
echo " PAT tuple production (\$PATPROD): $PATPROD"
echo " LumiCalc (\$LUMI): $LUMI"
echo " HZZ Features (MELA etc) (\$HZZ): $HZZ"

if [ -z "FORCERECIPE" ]; then
   while true; do
       read -p "Do you wish continue? " yn
       case $yn in
           [Yy]* ) echo "sounds good dude"; break;;
           [Nn]* ) exit 2;;
           * ) echo "Please answer yes or no.";;
       esac
   done
fi

./recipe_mvamet.sh


LIMITS=$LIMITS PATPROD=$PATPROD ./recipe_legacy8TeV.sh


LUMI=$LUMI LIMITS=$LIMITS PATPROD=$PATPROD ./recipe_common.sh


echo "Kill the ssh-agent"
eval `ssh-agent -k` 

cd $CMSSW_BASE/src

