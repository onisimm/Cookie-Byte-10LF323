import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "PdfQuick"
    Depends { name: "Qt"; submodules: ["quick-private","pdf-private","core","gui","qml"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
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
    libNameForLinkerDebug: "Qt6PdfQuick"
    libNameForLinkerRelease: "Qt6PdfQuick"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6PdfQuick.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_PDFQUICK_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtPdfQuick"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["pdfquick"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
