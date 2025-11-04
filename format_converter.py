"""Program converts all Jupyter Notebook (*.ipynb) files into given format
"""

import sys
import os
import subprocess
import argparse
import shutil
from typing import Any


def convert(input_file: str, output_file: str, oformat='pdf') -> Any:
    """Convert file format

    Args:
        input_file (str): input file
        output_file (str): output file
        oformat (str, optional): Format to convert to. Defaults to 'pdf'.

    Returns:
        stderr
    """
    print(input_file, output_file, oformat, file=sys.stderr)
    out = subprocess.Popen(
        ['jupyter', 'nbconvert', '--to', oformat,
         input_file, '--output', output_file])
    _, stderr = out.communicate()
    return stderr


def convert_to_latex(files: list[str], input_dir: str, output_dir: str) -> None:
    """ Function to convert list of files in input_dir to Latex.

    Args:
        files (list[str]): list of files
        input_dir (str): directory that contains the inout files
        output_dir (str): output directory to save Latex file to
    """
    errors: list[Any] = []
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    shutil.copytree('resources', os.path.join(output_dir, 'resources'))
    for inf in files:
        output_file = os.path.join(output_dir, inf.split('.')[0])
        error = convert(os.path.join(input_dir, inf), output_file, 'latex')
        if error:
            errors.append(error)
    print(errors, file=sys.stderr)


def convert_to_pdfs(output_dir: str) -> None:
    """Function to convert ipynb into pdfs

    Args:
        output_dir (str): output folder
    """
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    os.mkdir('pdfs')
    files = [f for f in os.listdir('latex') if f.endswith('.tex')]
    file_ext = ['*.aux', '*.log', '*.out']
    for f in files:
        path = os.path.join('latex', f)
        with open(path, 'r', encoding='utf-8') as fin:
            latex = fin.read()
            latex = latex.replace('.ipynb', '.pdf')
        with open(path, 'w', encoding='utf-8') as fout:
            fout.write(latex)

        cmd = f'pdflatex -output-directory={output_dir} {path}'
        print(cmd)
        process = subprocess.run(cmd.split())
        # output, error = process.communicate()
        # print(output)
        subprocess.run(['clear'])
    for ext in file_ext:
        cmd = 'rm ' + os.path.join(output_dir, ext)
        print(cmd)
        process = subprocess.run(cmd.split())
        # process.communicate()

    print('all done! see pdfs folder...')


def main():
    parser = argparse.ArgumentParser(description="Notebook converter")
    parser.add_argument('-id', '--inputDir', default=".",
                        help="Input Folder; default is current folder the script is running from")
    parser.add_argument('-f', '--format', default="pdf",
                        help="conversion type; default is pdf other options: pdf, latex, html, webpdf, slides")
    parser.add_argument('-od', '--outputDir', default="pdfs",
                        help="Output folder to save the converted files; default is pdfs inside input folder.")
    # parser.add_argument('-if', '--inputFile', help="Input notebook file to convert")
    args = vars(parser.parse_args())  # convert Namespace to dict()
    # print(args)
    # print(os.listdir(args['inputFolder']))
    files = [f for f in os.listdir(args['inputDir']) if f.endswith('.ipynb')]
    errors = []
    format_type = args['format']
    output_dir = os.path.join(args['inputDir'], args['outputDir'])
    input_dir = args['inputDir']
    if format_type == 'latex':
        convert_to_latex(files, input_dir, output_dir)
    elif format_type == 'pdf':
        convert_to_latex(files, input_dir, "latex")
        convert_to_pdfs(output_dir)

    print(f'Total {len(files)} notebooks found in {args["inputDir"]} folder.')
    print(f'Total {len(errors)} errors:')
    print('\n'.join(errors))


if __name__ == "__main__":
    main()
