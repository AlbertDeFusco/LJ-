import sys
import numpy as np
import os
import argparse

def make_cluster(natoms, radius=2, seed=1981):
    if seed is not None:
        np.random.seed(seed)

    cluster = np.random.normal(0, radius, size=(natoms,3))-0.5
    return cluster


def write(cluster, filename, append=False):
    mode = 'ab' if append else 'wb'

    fmt = 'Ar %12.8f %12.8f %12.8f'
    c = cluster

    with open(filename, mode) as f:
        header = '{:d}\n# Randomly generated positions'.format(cluster.shape[0])
        np.savetxt(f, c, header=header, comments='', fmt=fmt)

def cli():
    parser = argparse.ArgumentParser(
            description='Write an XYZ file with random positions',
            formatter_class = argparse.ArgumentDefaultsHelpFormatter
            )

    parser.add_argument('size', help='Number of particles', type=int)
    parser.add_argument('filename', help='Path and filename to write XYZ file')
    parser.add_argument('-r', '--radius', help='Radius in which to fill with particles',
            type=int,
            default=100)
    parser.add_argument('-s', '--seed', help='Random seed', default=None, type=int)

    return parser

def main(args):
    print('Generating cluster of {} particles.'.format(args.size))
    c = make_cluster(args.size, args.radius, args.seed)

    write(c, args.filename)
    print('File written to {}'.format(args.filename))

if __name__ == '__main__':
    args = cli().parse_args()
    main(args)
