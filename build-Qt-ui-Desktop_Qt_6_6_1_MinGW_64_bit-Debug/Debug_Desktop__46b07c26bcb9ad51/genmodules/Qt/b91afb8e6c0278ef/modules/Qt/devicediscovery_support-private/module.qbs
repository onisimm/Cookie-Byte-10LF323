import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "DeviceDiscoverySupport"
    Depends { name: "Qt"; submodules: ["core-private"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["mpr","userenv"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6DeviceDiscoverySupport"
    libNameForLinkerRelease: "Qt6DeviceDiscoverySupport"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6DeviceDiscoverySupport.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_DEVICEDISCOVERY_SUPPORT_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtDeviceDiscoverySupport","C:/Qt/6.6.1/mingw_64/include/QtDeviceDiscoverySupport/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtDeviceDiscoverySupport/6.6.1/QtDeviceDiscoverySupport"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["devicediscovery_support-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
