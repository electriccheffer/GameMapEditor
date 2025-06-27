#!/bin/bash

# Check that the bin directory exists
	# if not make bin 
if [ -d "$HOME/bin" ]; then
	echo "~/bin directory exists"
else
	mkdir -p "$HOME/bin"
fi

# Check that bin is in the path
	# if not add the bin to the path 
# Copy the build to the bin directory

