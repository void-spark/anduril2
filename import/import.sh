#!/bin/bash
docker run -it --rm -v `pwd`/import:/root/import -w /root/import debian:buster bash -c "\
apt update && \
apt upgrade && \
apt -y install bzr-fastimport git && \
mkdir anduril2 && \
cd anduril2 && \
bzr branch lp:~toykeeper/flashlight-firmware/anduril2 && \
mv anduril2/ anduril2.tk && \
bzr branch lp:~gabe/flashlight-firmware/anduril2 && \
mv anduril2 anduril2.gabe && \
git init git-repo && \
cd git-repo && \
bzr fast-export --export-marks=../marks.bzr ../anduril2.tk | \
git fast-import --export-marks=../marks.git && \
bzr fast-export --marks=../marks.bzr --git-branch=gabe ../anduril2.gabe | \
git fast-import --import-marks=../marks.git --export-marks=../marks.git && \
git reset --hard HEAD"
