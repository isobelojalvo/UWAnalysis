#!/bin/sh
sleep 2h
for i in {1..12}
do
    nohup bash submitDATAReReco.sh --resubmit-failed-jobs >>logResubmitDataScript
    nohup bash submitReRecoMC.sh --resubmit-failed-jobs >>logResubmitDataScript
    sleep 1h
done