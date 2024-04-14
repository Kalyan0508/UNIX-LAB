#!/bin/bash

# Define the list of remote machines
machines=("student@192.168.148.27" "student@192.168.148.31")

# Iterate over each machine and retrieve memory and CPU usage
for machine in "${machines[@]}"; do
    echo "Memory and CPU usage for $machine:"

    # SSH into the remote machine and retrieve memory usage
    echo "Memory Usage:"
    ssh "$machine" 'free -m'

    # SSH into the remote machine and retrieve CPU usage
    echo "CPU Usage:"
    ssh "$machine" 'mpstat'

    echo
done
