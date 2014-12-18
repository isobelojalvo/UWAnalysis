#!/bin/env python

import sys
from ROOT import TFile, TTree

from optparse import OptionParser

parser = OptionParser()

parser.add_option("-c", "--cut", dest="cut",
                  default='1',
                  help='cut to define passing events')

parser.add_option("-t", "--tree", dest="tree",
                  default='TauCheck',
                  help='name of the tree')

(options,args) = parser.parse_args()
if len(args)!=1:
    print 'provide input root file'
    sys.exit(1)
    
file = TFile( args[0] )

treeName = options.tree
cut = options.cut

tree = file.Get(treeName)
tree.SetScanField(0)
tree.Scan('evt', cut, "colsize=15")
