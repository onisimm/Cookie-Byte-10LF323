import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "PdfQuick"
    Depends { name: "Qt"; submodules: ["pdfquick"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: false
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: undefined
    libNameForLinkerRelease: undefined
    libFilePathDebug: undefined
    libFilePathRelease: undefined
    pluginTypes: []
    moduleConfig: []
    cpp.defines: []
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtPdfQuick/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtPdfQuick/6.6.1/QtPdfQuick"]
    cpp.libraryPaths: []
    
}
