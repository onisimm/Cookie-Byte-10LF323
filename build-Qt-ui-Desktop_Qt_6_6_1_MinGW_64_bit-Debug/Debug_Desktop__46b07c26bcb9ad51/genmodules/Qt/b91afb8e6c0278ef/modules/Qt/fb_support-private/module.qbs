import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "FbSupport"
    Depends { name: "Qt"; submodules: ["core-private","gui-private"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["mpr","userenv","d3d11","dxgi","dxguid","d3d12"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6FbSupport"
    libNameForLinkerRelease: "Qt6FbSupport"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6FbSupport.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_FB_SUPPORT_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtFbSupport","C:/Qt/6.6.1/mingw_64/include/QtFbSupport/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtFbSupport/6.6.1/QtFbSupport"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["fb_support-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
