#!/bin/bash

ROOT_PATH=$(dirname $(pwd))
echo Using folder: $ROOT_PATH
USER_UID=$(id -u)
USER_GID=$(id -g)
USER_NAME=$(id -n -u)
USER_GROUP=$(id -n -g)
INIT_FILE=/home/$USER_NAME/.profile

docker run -it --rm -v $ROOT_PATH:$ROOT_PATH -w $ROOT_PATH anduril2_arch /bin/bash -c "\
groupadd -g $USER_GID `id -n -g`;\
useradd -u $USER_UID -g $USER_GID $USER_NAME;\
echo 'export ATTINY_DFP=/opt/dfp' >> $INIT_FILE;\
echo 'cd $ROOT_PATH/ToyKeeper/spaghetti-monster/anduril/' >> $INIT_FILE;\
echo 'echo Hello!' >> $INIT_FILE;\
su -s /bin/bash --login $USER_NAME"
