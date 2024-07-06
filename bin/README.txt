To allow name and port changes from admintool, mudos.cfg
is not a link to a file inside the mudlib.

If you hose that file or that link, copy the original
in this directory (mudos.cfg.bak) to ../lib/secure/cfg/mudos.cfg 
and recreate the link. 

The commands, from this directory, are:
--------------------------------------

cp mudos.cfg.bak ../lib/secure/cfg/mudos.cfg

ln -s ../lib/secure/cfg/mudos.cfg mudos.cfg

- added scribe directory with backup shell scripts. Tried to 
  keep it distribution-agnostic to use as you see fit. In 
  example, I have the granular script running the first 
  Monday of each month and the full backup every third Sunday.
