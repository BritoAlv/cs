import os

#Python3 Code @BritoAlv
result = ""
result += "\\documentclass{article}\n\
\\usepackage{geometry}\n\
\\geometry{a4paper, margin=0.5in} % Reduced margins\n\
\\usepackage[T1]{fontenc}\n\
\\usepackage{listings}\n\
\\usepackage{xcolor}\n\
\\usepackage[scaled=.85]{beramono}\n\
\\usepackage{graphicx}\n\
\\usepackage{pdflscape}\n\
\\usepackage{multicol}\n\
\n\
\\lstset{\n\
    basicstyle=\\ttfamily\\footnotesize, % Reduced font size\n\
    breaklines=true,\n\
    frame=none, % Removed frame\n\
    linewidth=\\columnwidth,\n\
    lineskip=-1pt % Reduced line spacing\n\
}\n\
\n\
\\begin{document}\n\
\n\
\\begin{landscape}\n\
\\begin{titlepage}\n\
    \\centering\n\
    \\vspace*{1in}\n\
    \n\
    \\Huge\n\
    \\textbf{Team Reference}\n\
    \n\
    \\vspace{0.5in}\n\
    \\LARGE\n\
    \\textbf{Event: Caribbean Finals 2025} \\\\\n\
    [0.5cm]\n\
    \\textbf{Team Name: K3,3} \\\\\n\
    [0.5cm]\n\
    \\textbf{University: University of Havana (MATCOM)} \\\\\n\
    \n\
    \\vfill\n\
    \n\
    \\Large\n\
    \\textbf{Members:} \\\\\n\
    Luis Alejandro Arteaga Morales \\\\\n\
    Alvaro Luis Gonzalez Brito \\\\\n\
    Ahmed Rodriguez Martinez \\\\\n\
    \n\
    \\vspace{0.5in}\n\
    \n\
    \\textbf{Coach:} \\\\\n\
    Hiram Borbolla \\\\\n\
    \n\
    \\vfill\n\
    \n\
    \\vspace{0.5in}\n\
    \n\
    \\Large\n\
    \\textbf{Date:} \\\\\n\
    \\today\n\
    \n\
\\end{titlepage}\n\
\n\
\\newpage\n\
\n\
\\tableofcontents\n\
\n\
\\newpage\n\
\n\
\\setlength{\\columnseprule}{0.4pt}\n\
\\begin{multicols}{2}\n"

for file in os.listdir('./Codes'):
    with open(f'./Codes/{file}', 'r') as f:
        name = file.split('.')[0]
        result += "\\subsection{" + name + "}" + "\n\
\\vspace{0.2cm}\n\
\\hrule\n\
\\lstinputlisting[language=C++]{Codes/" + file + "}\n"

result += "\\end{multicols}\n\
\\end{landscape}\n\
\\end{document}"

with open('references.tex', 'w') as new_ref_file:
    new_ref_file.write(result)