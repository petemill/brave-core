#include "chrome/browser/ui/layout_constants.h"
#include "brave/browser/ui/views/toolbar/bookmark_button.h"
#include "brave/browser/ui/views/location_bar/location_bar_wrapper_view.h"
#include "chrome/browser/ui/views/toolbar/toolbar_view.h"
#include "chrome/browser/ui/views/location_bar/location_bar_view.h"
#include "chrome/browser/command_updater.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/ui/browser.h"

const char BraveLocationBarWrapperView::kViewClassName[] = "BraveLocationBarWrapperView";


BraveLocationBarWrapperView::BraveLocationBarWrapperView(Browser* browser,
                                 Profile* profile,
                                 CommandUpdater* command_updater,
                                 ToolbarView* toolbar_view,
                                 bool is_popup_mode) {
  location_bar_ = new LocationBarView(
    browser,
    profile,
    command_updater,
    toolbar_view,
    is_popup_mode
  );
  bookmark_button_ = new BookmarkButton(toolbar_view);
}

BraveLocationBarWrapperView::~BraveLocationBarWrapperView() { }

void BraveLocationBarWrapperView::Init() {

  bookmark_button_->set_triggerable_event_flags(ui::EF_LEFT_MOUSE_BUTTON | ui::EF_MIDDLE_MOUSE_BUTTON);
  bookmark_button_->Init();

  AddChildView(location_bar_);
  AddChildView(bookmark_button_);

  location_bar_->Init();
}

bool BraveLocationBarWrapperView::IsInitialized() const {
  return location_bar_->IsInitialized();
}

// Helper to get the color for |part| using the current tint().
SkColor BraveLocationBarWrapperView::GetColor(OmniboxPart part) const {
  return location_bar_->GetColor(part);
};

// Returns the location bar border color blended with the toolbar color.
// It's guaranteed to be opaque.
SkColor BraveLocationBarWrapperView::GetOpaqueBorderColor(bool incognito) const {
  return location_bar_->GetOpaqueBorderColor(incognito);
};

// Returns the color to be used for the security chip in the context of
// |security_level|.
SkColor BraveLocationBarWrapperView::GetSecurityChipColor(
    security_state::SecurityLevel security_level) const {
      return location_bar_->GetSecurityChipColor(security_level);
};

// Toggles the bookmark icon on or off.
void BraveLocationBarWrapperView::SetStarToggled(bool on) {
  bookmark_button_->SetToggled(on);
};

// Returns the screen coordinates of the omnibox (where the URL text appears,
// not where the icons are shown).
gfx::Point BraveLocationBarWrapperView::GetOmniboxViewOrigin() const {
  return location_bar_->GetOmniboxViewOrigin();
};

// Shows |text| as an inline autocompletion.  This is useful for IMEs, where
// we can't show the autocompletion inside the actual OmniboxView.  See
// comments on |ime_inline_autocomplete_view_|.
void BraveLocationBarWrapperView::SetImeInlineAutocompletion(const base::string16& text) {
  location_bar_->SetImeInlineAutocompletion(text);
};

// Paints a custom focus ring on platforms that normally do not show focus
// rings if |full_keyboard_accessibility_mode| is set to true.
// TODO(tommycli): Remove this after after Material Refresh is launched.
void BraveLocationBarWrapperView::SetFullKeyboardAcessibilityMode(bool full_keyboard_accessibility_mode) {
  location_bar_->SetFullKeyboardAcessibilityMode(full_keyboard_accessibility_mode);
};

// Select all of the text. Needed when the user tabs through controls
// in the toolbar in full keyboard accessibility mode.
void BraveLocationBarWrapperView::SelectAll() {
  location_bar_->SelectAll();
};

// The anchor view for security-related bubbles. That is, those anchored to
// the leading edge of the Omnibox, under the padlock.
views::View* BraveLocationBarWrapperView::GetSecurityBubbleAnchorView() {
  return location_bar_->GetSecurityBubbleAnchorView();
};

// Show a page info dialog for |web_contents|.
// Returns true if a dialog was shown, false otherwise.
bool BraveLocationBarWrapperView::ShowPageInfoDialog(content::WebContents* web_contents) {
  return location_bar_->ShowPageInfoDialog(web_contents);
};

// Updates the controller, and, if |contents| is non-null, restores saved
// state that the tab holds.
void BraveLocationBarWrapperView::Update(const content::WebContents* contents) {
  location_bar_->Update(contents);
};

// Clears the location bar's state for |contents|.
void BraveLocationBarWrapperView::ResetTabState(content::WebContents* contents) {
  location_bar_->ResetTabState(contents);
};

// Activates the first visible but inactive PageActionIconView for
// accessibility.
bool BraveLocationBarWrapperView::ActivateFirstInactiveBubbleForAccessibility() {
  return location_bar_->ActivateFirstInactiveBubbleForAccessibility();
};

// LocationBar:
void BraveLocationBarWrapperView::FocusLocation(bool select_all) {
  location_bar_->FocusLocation(select_all);
}

// void Revert() override;
// OmniboxView* GetOmniboxView() override;

// views::View:
bool BraveLocationBarWrapperView::HasFocus() const {
  return location_bar_->HasFocus();
}

void BraveLocationBarWrapperView::GetAccessibleNodeData(ui::AXNodeData* node_data) {
  location_bar_->GetAccessibleNodeData(node_data);
}

gfx::Size BraveLocationBarWrapperView::CalculatePreferredSize() const {
  return location_bar_->CalculatePreferredSize();
}

void BraveLocationBarWrapperView::Layout() {

  gfx::Size bookmarkSize = bookmark_button_->GetPreferredSize();
  const int toolbar_button_height =
      std::min(bookmarkSize.height(), height());
  const int toolbar_button_y = (height() - toolbar_button_height) / 2;

  bookmark_button_->SetBounds(0, toolbar_button_y, bookmarkSize.height(), bookmarkSize.width());
  int next_element_x = bookmark_button_->bounds().right() + GetLayoutConstant(TOOLBAR_STANDARD_SPACING);
  location_bar_->SetBounds(next_element_x, 0, width(), height());
}

void BraveLocationBarWrapperView::OnThemeChanged() {
  location_bar_->OnThemeChanged();
}

void BraveLocationBarWrapperView::OnNativeThemeChanged(const ui::NativeTheme* theme) {
  location_bar_->OnNativeThemeChanged(theme);
}

void BraveLocationBarWrapperView::ChildPreferredSizeChanged(views::View* child) {
  location_bar_->ChildPreferredSizeChanged(child);
}

// ChromeOmniboxEditController:
// void UpdateWithoutTabRestore() override;
// ToolbarModel* GetToolbarModel() override;
// content::WebContents* GetWebContents() override;

// ContentSettingImageView::Delegate:
// content::WebContents* GetContentSettingWebContents() override;
// ContentSettingBubbleModelDelegate* GetContentSettingBubbleModelDelegate()
//     override;

// views::ButtonListener:
// void ButtonPressed(views::Button* sender, const ui::Event& event) override;

bool BraveLocationBarWrapperView::IsVirtualKeyboardVisible(views::Widget* widget) {
  return LocationBarView::IsVirtualKeyboardVisible(widget);
};

// Returns the height available for user-entered text in the location bar.
int BraveLocationBarWrapperView::GetAvailableTextHeight() {
  return LocationBarView::GetAvailableTextHeight();
};

// Returns the height available for text within location bar decorations.
int BraveLocationBarWrapperView::GetAvailableDecorationTextHeight() {
  return LocationBarView::GetAvailableDecorationTextHeight();
};

void BraveLocationBarWrapperView::OnOmniboxFocused() {
  location_bar_->OnOmniboxFocused();
};
void BraveLocationBarWrapperView::OnOmniboxBlurred() {
  location_bar_->OnOmniboxBlurred();
};
