#!/usr/bin/env bash

set -e

if [ $# -eq 0 ]
  then
    docker build -t utilforever/hellsolver .
else
    docker build -f $1 -t utilforever/hellsolver:$2 .
fi
docker run utilforever/hellsolver