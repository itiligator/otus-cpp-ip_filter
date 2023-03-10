#!/bin/sh
EXPECTED_RESULT="24e7a7b2270daee89c64d3ca5fb3da1a  -"
GOT_RESULT=$(cat tests/ip_filter.tsv | ./ip_filter | md5sum)
if [ "$EXPECTED_RESULT" = "$GOT_RESULT" ];
then
  echo "OK"
  exit 0
else
  echo "not OK"
  exit 1
fi
