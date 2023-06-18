#!/bin/bash
docker run -it --rm -v `pwd`/update:/root/update -w /root/update debian:buster bash -c "\
apt update && \
apt -y install bzr-fastimport git && \
git clone https://github.com/void-spark/anduril2.git && \
mkdir upstream && \
cd upstream && \
bzr branch lp:~toykeeper/flashlight-firmware/anduril2 && \
mv anduril2 anduril2.tk && \
bzr branch lp:~gabe/flashlight-firmware/anduril2 && \
mv anduril2 anduril2.gabe && \
cd .. && \
cd anduril2 && \
git remote set-url origin git@github.com:void-spark/anduril2.git && \
bzr fast-export --marks=./import/marks.bzr --git-branch=toykeeper ../upstream/anduril2.tk | \
git fast-import --import-marks=./import/marks.git --export-marks=./import/marks.git && \
bzr fast-export --marks=./import/marks.bzr --git-branch=gabe ../upstream/anduril2.gabe | \
git fast-import --import-marks=./import/marks.git --export-marks=./import/marks.git && \
sort ./import/marks.bzr -n -k 1.2 -o ./import/marks.bzr"

# git commit -a -m 'Update mark files after updating upstream branches'`date -Iminutes`
# git push origin --all
