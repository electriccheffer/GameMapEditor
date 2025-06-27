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
INSTALL_TARGET="$HOME/bin"
case ":$PATH:" in
	*":$INSTALL_TARGET:"*)
		echo "~/bin is in PATH"
		;;
	*)
		echo "~/bin is not in the PATH.  Adding to PATH"
		echo 'export PATH="$INSTALL_TARGET:$PATH"' >> "$HOME/.bashrc"

esac

cp ./build/ObjectEditor ~/bin

echo 'ObjectEditor has been installed at ~/bin. Close this window and open a new terminal.  <3Type ObjectEditor to run the application!<3'
# Copy the build to the bin directory

