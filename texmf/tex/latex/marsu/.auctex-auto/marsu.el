(TeX-add-style-hook
 "marsu"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("hyperref" "hidelinks") ("titlesec" "explicit") ("circuitikz" "straightvoltages") ("SIunits" "squaren" "cdot" "derived") ("esvect" "f") ("mhchem" "version=4") ("tcolorbox" "many") ("babel" "french")))
   (add-to-list 'LaTeX-verbatim-environments-local "lstlisting")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "href")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "inputenc"
    "fontenc"
    "lmodern"
    "geometry"
    "fancyhdr"
    "import"
    "hyperref"
    "titlesec"
    "amssymb"
    "mathtools"
    "titletoc"
    "etoc"
    "tabto"
    "ntheorem-hyper"
    "etoolbox"
    "ifthen"
    "xspace"
    "varioref"
    "multicol"
    "enumitem"
    "xcolor"
    "float"
    "tikz"
    "tkz-tab"
    "circuitikz"
    "SIunits"
    "graphicx"
    "esvect"
    "mhchem"
    "chemfig"
    "transparent"
    "tcolorbox"
    "babel"
    "listings"
    "eurosym")
   (TeX-add-symbols
    '("Resultat" 1)
    '("Definition" 1)
    '("dive" 1)
    '("conv" 1)
    '("point" 4)
    '("reperefonc" 2)
    '("barre" 1)
    '("bbox" 1)
    '("eq" 1)
    '("ext" 1)
    '("comp" 1)
    '("moment" 2)
    '("travail" 2)
    '("puissance" 1)
    '("dddt" 1)
    '("ddt" 1)
    '("dix" 1)
    '("interff" 2)
    '("interfo" 2)
    '("interof" 2)
    '("interoo" 2)
    '("chof" 1)
    '("cof" 1)
    '("pof" 1)
    '("id" 3)
    '("alg" 1)
    '("vect" 1)
    '("abs" 1)
    '("inv" 1)
    '("pow" 2)
    '("de" 2)
    '("e" 1)
    '("ProcessQuote" 1)
    '("ColorIfNotInString" 1)
    "refe"
    "gali"
    "refgal"
    "refes"
    "galis"
    "refgals"
    "ssi"
    "N"
    "Z"
    "D"
    "Q"
    "R"
    "C"
    "coosh"
    "sh"
    "argch"
    "argsh"
    "argth"
    "cotan"
    "x"
    "tr"
    "drm"
    "po"
    "pf"
    "co"
    "cf"
    "ux"
    "uy"
    "uz"
    "ur"
    "uth"
    "uph"
    "om"
    "vvi"
    "vvio"
    "va"
    "vp"
    "fr"
    "vabla"
    "grad"
    "diverg"
    "rot"
    "dt"
    "ph"
    "oxonium"
    "eau"
    "hydroxyle"
    "ah"
    "amoins"
    "p"
    "reperetroisd"
    "reperedeuxd")
   (LaTeX-add-environments
    "Def"
    "result")
   (LaTeX-add-xcolor-definecolors
    "codegray"
    "backcolour")
   (LaTeX-add-tcolorbox-newtcolorboxes
    '("titre" "1" "[" ""))
   (LaTeX-add-tcbuselibraries
    "skins")
   (LaTeX-add-listings-lstdefinestyles
    "Python"))
 :latex)

