#!/bin/sh
for i in {1..12}
do
    sleep 1h
    nohup bash submitDATA.sh --resubmit-failed-jobs >>logResubmitDataScript
    nohup bash submitMCTT.sh --resubmit-failed-jobs >>logResubmitMCScript

done