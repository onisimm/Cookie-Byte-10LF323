import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DHelpersImpl"
    Depends { name: "Qt"; submodules: []}

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
    libNameForLinkerDebug: "Qt6Quick3DHelpersImpl"
    libNameForLinkerRelease: "Qt6Quick3DHelpersImpl"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DHelpersImpl.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DHELPERSIMPL_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3DHelpersImpl"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3dhelpersimpl"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
