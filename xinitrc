if [ -d /etc/X11/xinit/xinitrc.d ] ; then
  for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
    [ -x "$f" ] && . "$f"
  done
  unset f
fi

setxkbmap se
xmodmap ~/src/dotfiles/xkb/Xmodmap
xrdb ~/src/dotfiles/Xresources
urxvtd -q -f -o
exec i3
