#!/usr/bin/python

from tokenize import tokenize, untokenize, NUMBER, STRING, NAME, OP
from token import NAME, INDENT, tok_name
from io import BytesIO
import sys

if len(sys.argv) < 3:
  print('you need to specify a name and a property')
  exit()

name = sys.argv[1].lower()
prop = sys.argv[2].lower()

while True:
  line = sys.stdin.readline()
  if not line: break
  if not line.lower().startswith(name): continue

  while True:
    line = sys.stdin.readline()
    if not line: break
    if not line.startswith(' '): break
    split = line.split(':')
    if len(split) < 2: continue
    if split[0].lstrip(' ').lower().startswith(prop):
      print(split[1].lstrip(' ').rstrip('\n'))
  break

