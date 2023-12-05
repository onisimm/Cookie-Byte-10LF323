import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "LabsSharedImage"
    Depends { name: "Qt"; submodules: ["core-private","gui-private","quick-private"]}

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
    libNameForLinkerDebug: "Qt6LabsSharedImage"
    libNameForLinkerRelease: "Qt6LabsSharedImage"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6LabsSharedImage.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_LABSSHAREDIMAGE_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtLabsSharedImage"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["labssharedimage"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
