#!/bin/sh
for i in {1..24}
do
    sleep 2h
    nohup bash submitDATA.sh --resubmit-failed-jobs >>logResubmitDataScript
    nohup bash submitMCTT.sh --resubmit-failed-jobs >>logResubmitMCScript
    nohup bash submitMCTT-rehlt.sh --resubmit-failed-jobs >>logResubmitMCrehltScript
done