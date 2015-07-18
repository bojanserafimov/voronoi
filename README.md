
# Install dependenciess

## Install GTK+

First try `sudo apt-get install libgtk-3-dev`. 
If it doesn't work, install from source

```sh
sudo apt-get install 'libglib2.0-dev'
sudo apt-get install 'libatk-bridge2.0-*'
sudo apt-get install 'libatk1.0*'
sudo apt-get install 'libpango1.0*'
sudo apt-get install 'fontconfig'
sudo apt-get install 'libgdk-pixbuf2.0*'
```

```sh
cd ~/Downloads
wget http://ftp.gnome.org/pub/gnome/sources/gtk+/3.10/gtk+-3.10.9.tar.xz
tar xvfJ gtk+-3.10.9.tar.xz
rm gtk+-3.10.9.tar.xz
cd gtk+-3.10.9
./configure --prefix=/opt/gtk
make
sudo make install
```

## Install cmocka

```sh
cd ~/Downloads
wget https://cmocka.org/files/1.0/cmocka-1.0.0.tar.xz
tar xvfJ cmocka-1.0.0.tar.xz
rm cmocka-1.0.0.tar.xz
cd cmocka-1.0.0
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=DEBUG ..
make
sudo make install


