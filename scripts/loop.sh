#!/bin/bash

for p in {-25..25}
do
	./mtd_timing -b -m run_1.mac -p $p
done
