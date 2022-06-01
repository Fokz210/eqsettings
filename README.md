# EqualizerAPO mini cli plugin state configurator

This program is a cli interface for the [EqualizerAPO](https://sourceforge.net/projects/equalizerapo/).  

## Configuration
You can set config file path in file 'EQSettings.ini' which is created on first run.
For now, you need to add plugins by EqualizerAPO GUI. This cli can only switch their state. 

## Usage
- Switch plugin state: `$ ./EQSettings.exe [plugin index]`
- Turn all plugins off: `$ ./EQSettings.exe off`
- Turn all plugins on: `$ ./EQSettings.exe all` 

You can also combine commands:
    
    $ ./EQSettings.exe off 1 2 3 

### todo:
- add support for plugin arguments changing
- add plugin adding support

  