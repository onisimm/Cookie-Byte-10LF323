import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "DesignerComponents"
    Depends { name: "Qt"; submodules: ["core","designer-private","gui-private","widgets-private","xml"]}

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
    libNameForLinkerDebug: "Qt6DesignerComponents"
    libNameForLinkerRelease: "Qt6DesignerComponents"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6DesignerComponents.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_DESIGNERCOMPONENTS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtDesignerComponents","C:/Qt/6.6.1/mingw_64/include/QtDesignerComponents/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtDesignerComponents/6.6.1/QtDesignerComponents"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["designercomponents-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
