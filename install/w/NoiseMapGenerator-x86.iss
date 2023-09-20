; Script generated by the Inno Script Studio Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{28AF4D40-F68C-4C7D-A5FD-1A5DA723E46A}
AppName=Noise Map Generator
AppVersion=1.0.0.1
;AppVerName=Noise Map Generator 1.0.0.1
AppPublisher=Retro Technique
AppPublisherURL=https://github.com/RetroTechnique
AppSupportURL=https://github.com/RetroTechnique
AppUpdatesURL=https://github.com/RetroTechnique
DefaultDirName={pf}\Retro Technique\Noise Map Generator
DefaultGroupName=Noise Map Generator
LicenseFile=E:\Informatique\svn\NoiseMapGenerator\trunk\LICENSE
InfoBeforeFile=E:\Informatique\svn\NoiseMapGenerator\trunk\install\w\readme.txt
OutputDir=E:\Informatique\svn\NoiseMapGenerator\trunk\install
OutputBaseFilename=NoiseMapGenerator-1.0.0.1-x86
Compression=lzma
SolidCompression=yes

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "E:\Informatique\svn\NoiseMapGenerator\trunk\install\w\x86\NoiseMapGenerator.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "E:\Informatique\svn\NoiseMapGenerator\trunk\install\w\x86\ScionCore.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "E:\Informatique\svn\NoiseMapGenerator\trunk\install\w\x86\VC_redist.x86.exe"; DestDir: {tmp}; Flags: deleteafterinstall
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\Noise Map Generator"; Filename: "{app}\NoiseMapGenerator.exe"
Name: "{commondesktop}\Noise Map Generator"; Filename: "{app}\NoiseMapGenerator.exe"; Tasks: desktopicon

[Run]
Filename: {tmp}\vcredist_x86.exe; Parameters: "/q /passive /Q:a /c:""exec /q /i vcredist.exe"""; StatusMsg: "Installing VC++ x86 Redistributables..."
Filename: "{app}\NoiseMapGenerator.exe"; Description: "{cm:LaunchProgram,Noise Map Generator}"; Flags: nowait postinstall skipifsilent