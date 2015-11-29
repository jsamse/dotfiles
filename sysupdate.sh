#!/bin/bash

# Check for updates
yaourt -Sya
if yaourt -Qua
then
  echo "Updates available."
else
  echo "No updates available."
  exit 1
fi

# Remove oldest snapshot
if [ -e /dev/cryptogroup/arch_snapshot5 ]
then
  echo "Removing oldest snapshot."
  sudo lvremove -f cryptogroup/arch_snapshot5
fi

# Rename snapshots
for i in {4..1}
do
  if [ -e /dev/cryptogroup/arch_snapshot$i ]
  then
    echo "Moving snapshot number $i to $((i + 1))."
    sudo lvrename cryptogroup arch_snapshot$i arch_snapshot$((i + 1))
  fi
done

# Create new snapshot
echo "Creating new snapshot."
sudo lvcreate --size 5G --snapshot --name arch_snapshot1 cryptogroup/arch

# Update system
echo "Update system."
yaourt -Syua
