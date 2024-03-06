
#### Setup environment

```sh
sudo apt-get -y install doxygen graphviz binutils-dev
```

#### Build

```sh
mkdir build && cd build
cmake ..
make -j16
sudo make install
```

#### Sphinx + doxygen
就是doxygen生成xml，然后sphinx中配置使用breathe，将doxygen生成的xml引入到sphinx中来。
至于具体的文档内容，通过index.rst按照 sphinx和 breathe的语法进行添加。