# EtherBrowser

EtherBrowser is a lightweight, highly customizable, and minimalistic web browser for both **Linux** and **Windows**. Inspired by the keyboard-driven design of Vim, it is optimized for those who prefer command-line navigation and want a fast and responsive browsing experience.

## Features

- **Minimal UI**: No bloatware or unnecessary UI elements, focused on pure browsing.
- **Keyboard-Only Navigation**: Navigate without using a mouse, leveraging Vim-like commands for efficiency.
- **Customizable Settings**: Easily tweak the browser to your needs, supporting a range of personal configurations.
- **WebKitGTK**: Powered by WebKitGTK for rendering web pages.
- **Open Source**: Released under the GNU GPLv3 license, allowing for contributions and community-driven improvements.

## Requirements

### Linux:

- **GTK 3.0** or later
- **WebKitGTK** library
- **C++11** or later

### Windows:

- **GTK 3.0** or later (via MSYS2 or similar)
- **WebKitGTK** library (via MSYS2 or similar)
- **C++11** or later

## Installation

### 1. Clone the repository:

```bash
git clone https://github.com/yourusername/EtherBrowser.git
cd EtherBrowser
```
### 2. Install dependencies:

On Ubuntu-based distributions (Linux):
```bash
sudo apt-get install libgtk-3-dev libwebkit2gtk-4.1-dev build-essential cmake
```
On Windows:

You can install the dependencies using MSYS2. Follow these steps:

  1. Install MSYS2 from https://www.msys2.org/.
  2. Install GTK and WebKitGTK via MSYS2:
```bash
pacman -S mingw-w64-x86_64-gtk3 mingw-w64-x86_64-webkitgtk
```

### 3. Build the project:

```bash
mkdir build
cd build
cmake ..
make
```

### 4. Run EtherBrowser:

After building, you can run the browser with:
On Linux:
```bash
./EtherBrowser
```
On Windows:
Use the appropriate command to run from the MSYS2 shell or use a native IDE to launch the built executable.
### Usage
 - Search: Use the search bar to instantly search the web.
 - Commands: Press Ctrl + S to bring up the command interface.
   - Write a search query and press Enter to search.
   - Use : to execute commands (e.g., :help to view available commands).
     
### Contributing
We welcome contributions! If you'd like to contribute to EtherBrowser, please fork the repository, create a branch, and submit a pull request with your changes.
Steps for contributing:
    1. Fork the repository.
    2. Clone your forked repository to your local machine.
    3. Create a feature branch.
    4. Commit your changes.
    5. Push your changes and create a pull request.
### License
This project is licensed under the GNU General Public License v3.0 - see the LICENSE file for details.
```text
GNU GENERAL PUBLIC LICENSE
Version 3, 29 June 2007

Copyright (C) 2024 EtherOrganization
Everyone is permitted to copy and distribute verbatim copies of this license document, but changing it is not allowed.

EtherBrowser is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Matija Perovic is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.

```
