# EqualizerAPO mini cli plugin state configurator

This program is a cli interface for the [EqualizerAPO](https://sourceforge.net/projects/equalizerapo/).  

## Configuration
You can set config file path in file 'EQSettings.ini' which is created on first run.
For now, you need to add plugins by EqualizerAPO GUI. This cli can only switch their state. 

## Usage
`$ ./EQSettings.exe [command [args]]`
### Commands:
- Switch plugin state: `$ ./EQSettings.exe switch plugin # [more plugin #'s]`
- Turn all plugins off: `$ ./EQSettings.exe off [plugin #]` (if no plugin # present, turns off all the plugins)
- Turn all plugins on: `$ ./EQSettings.exe on [plugin #]`  (if no plugin # present, turns on all the plugins)

Examples:
    
    $ ./EQSettings.exe off switch 1 2
    $ ./EQSettings.exe off 1
    $ ./EQSettings.exe on 1 2  

### todo:
- add support for plugin arguments changing
- add plugin adding support

  