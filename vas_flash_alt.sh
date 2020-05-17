#!/bin/bash

#./mdloader_mac --first --download massdrop_ctrl_vasukesan.bin --restart

make massdrop/alt:vasukesan
mv massdrop_alt_vasukesan.bin ../mdloader/
cd ../mdloader/


read -r -p "Is the keyboard Device Firmware Update mode (Pin underneath board, or Fn+B (hold))? [Y/n] " input
 
case $input in
    [yY][eE][sS]|[yY])
 echo "Yes"
 ./mdloader_mac --first --download massdrop_alt_vasukesan.bin --restart
 ;;
    [nN][oO]|[nN])
 echo "No"
       ;;
    *)
 echo "Invalid input"
 exit 1
 ;;
esac