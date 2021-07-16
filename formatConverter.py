# program converts all notebook.ipynb files into given format

import os
import subprocess
import argparse
import shutil

def convert(inputFile, outputFile, format='pdf'):
    print(inputFile, outputFile, format)
    out = subprocess.Popen(['jupyter', 'nbconvert', '--to', format, inputFile, '--output', outputFile])
    stdout, stderr = out.communicate()
    return stderr

def convertToLatex(files, inputDir, outPutDir):
    errors = []
    if os.path.exists(outPutDir):
        shutil.rmtree(outPutDir)
    shutil.copytree('resources', os.path.join(outPutDir, 'resources'))
    for inf in files:
        outputFile = os.path.join(outPutDir, inf.split('.')[0])
        error = convert(os.path.join(inputDir, inf), outputFile, 'latex')
        if error:
            errors.append(errors)
    print(errors)

def convertToPdfs(outPutDir):
    import subprocess
    #outPutDir = '../pdfs/'
    if os.path.exists(outPutDir):
        shutil.rmtree(outPutDir)
    os.mkdir('pdfs')
    files = [f for f in os.listdir('latex') if f.endswith('.tex')]
    fileExt = ['*.aux', '*.log', '*.out']
    for f in files:
        path = os.path.join('latex', f)
        with open(path, 'r') as fin:
            latex = fin.read()
            latex = latex.replace('.ipynb', '.pdf')
        with open(path, 'w') as fout:
            fout.write(latex)

        cmd = f'pdflatex -output-directory={outPutDir} {path}'
        print(cmd)
        process = subprocess.run(cmd.split())
        #output, error = process.communicate()
        #print(output)
        subprocess.run(['clear'])
    for ext in fileExt:
        cmd = 'rm ' + os.path.join(outPutDir, ext)
        print(cmd)
        process = subprocess.run(cmd.split())
        #process.communicate()
        
    print('all done! see pdfs folder...')


def main():
    parser = argparse.ArgumentParser(description="Notebook converter")
    parser.add_argument('-id', '--inputDir', default=".", help="Input Folder; default is current folder the script is running from")
    parser.add_argument('-f', '--format', default="pdf", help="conversion type; default is pdf other options: pdf, latex, html, webpdf, slides")
    parser.add_argument('-od', '--outputDir', default="pdfs", help="Output folder to save the converted files; default is pdfs inside input folder.")
    #parser.add_argument('-if', '--inputFile', help="Input notebook file to convert")
    args = vars(parser.parse_args()) # convert Namespace to dict()
    #print(args)
    #print(os.listdir(args['inputFolder']))
    files = [f for f in os.listdir(args['inputDir']) if f.endswith('.ipynb')]
    errors = []
    formatType = args['format']
    outPutDir = os.path.join(args['inputDir'], args['outputDir'])
    inputDir = args['inputDir']
    if formatType == 'latex':
        convertToLatex(files, inputDir, outPutDir)
    elif formatType == 'pdf':
        convertToLatex(files, inputDir, "latex")
        convertToPdfs(outPutDir)

    print(f'Total {len(files)} notebooks found in {args["inputDir"]} folder.')
    print(f'Total {len(errors)} errors:')
    print('\n'.join(errors))

if __name__ == "__main__":
    main()



