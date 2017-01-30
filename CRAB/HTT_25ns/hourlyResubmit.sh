#!/bin/sh
for i in {1..24}
do
    nohup bash submitDATA.sh --resubmit-failed-jobs >>logResubmitDataScript
    nohup bash submitMCTT.sh --resubmit-failed-jobs >>logResubmitMCScript
    sleep 1h
    
done