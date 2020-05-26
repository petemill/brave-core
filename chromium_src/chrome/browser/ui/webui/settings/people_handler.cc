#include "brave/common/webui_url_constants.h"
#include "brave/components/brave_sync/brave_sync_prefs.h"
#include "brave/components/brave_sync/crypto/crypto.h"
#include "chrome/browser/sync/device_info_sync_service_factory.h"
#include "components/sync_device_info/device_info_sync_service.h"
#include "components/sync_device_info/device_info_tracker.h"


#define BRAVE_CLOSE_SYNC_SETUP                                    \
  syncer::SyncService* sync_service = GetSyncService();           \
  if (sync_service &&                                             \
      !sync_service->GetUserSettings()->IsFirstSetupComplete()) { \
    DVLOG(1) << "Sync setup aborted by user action";              \
    sync_service->StopAndClear();                                 \
    brave_sync::Prefs brave_sync_prefs(profile_->GetPrefs());     \
    brave_sync_prefs.Clear();                                     \
  }

#define BRAVE_IS_SYNC_SUBPAGE \
  return (current_url == chrome::GetSettingsUrl(kBraveSyncSetupPath));

// IsSetupInProgress isn't accurate in brave sync flow especially for the first
// time setup, we rely on it to display setup dialog
#define BRAVE_GET_SYNC_STATUS_DICTIONARY  \
  sync_status->SetBoolean(                \
      "firstSetupInProgress",             \
      service && !disallowed_by_policy && \
          !service->GetUserSettings()->IsFirstSetupComplete());

#include "../../../../../../../chrome/browser/ui/webui/settings/people_handler.cc"
#undef BRAVE_CLOSE_SYNC_SETUP
#undef BRAVE_IS_SYNC_SUBPAGE
#undef BRAVE_GET_SYNC_STATUS_DICTIONARY
