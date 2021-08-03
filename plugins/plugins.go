package plugins

import (
	"github.com/wailsapp/wails"

	. "ytd/models"
)

type Plugin interface {
	GetName() string
	Initialize() error
	SetDir(dir string)
	Fetch(url string, isFromClipboard bool)
	StartDownload(ytEntry *GenericEntry) GenericEntry
	GetFilename() error
	Supports(address string) bool
	SetWailsRuntime(*wails.Runtime)
	SetAppConfig(config *AppConfig)
	SetAppStats(stats *AppStats)
}
