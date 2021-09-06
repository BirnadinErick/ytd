import { Entry } from './entry';

export interface AppConfig {
  BaseSaveDir: string;
  ClipboardWatch: boolean;
  ConcurrentDownloads: boolean;
  ConcurrentPlaylistDownloads: boolean;
  DownloadOnCopy: boolean;
  MaxParrallelDownloads: number;
  ConvertToMp3: boolean;
  CleanWebmFiles: boolean;
	RunInBackgroundOnClose: boolean;
	CheckForUpdates: boolean;
	StartAtLogin: boolean;
  Telegram: {
    Share: boolean;
    Username: string
  }
}

export interface AppState {
  entries: Entry[];
  config: AppConfig;
  appVersion: string;
}


export interface BackendCallbacks {
  main: {
    AppState: {
      GetAppConfig: () => Promise<any>;
      SelectDirectory: () => Promise<string>
      IsSupportedUrl: (url: string) => Promise<boolean>;
      AddToDownload: (url: string, isFromClipboard: boolean) => Promise<any>;
      StartDownload: (entry: Entry) => Promise<any>;
      ReadSettingBoolValue: (name: string) => Promise<any>;
      ReadSettingValue: (name: string) => Promise<any>;
      SaveSettingBoolValue: (name: string, val: boolean) => Promise<any>;
      SaveSettingValue: (name: string, val: string) => Promise<any>;
      RemoveEntry: (entry: Entry) => Promise<any>;
      IsFFmpegInstalled: () => Promise<boolean>;
      OpenUrl: (url: string) => Promise<any>;
      Update: (restart: boolean) => Promise<any>;
      ShowWindow: () => Promise<any>;
      ForceQuit: () => Promise<any>;
    }
  }
}
