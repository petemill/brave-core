#ifndef BRAVE_BROWSER_UI_VIEWS_LOCATION_BAR_BRAVE_LOCATION_BAR_WRAPPER_VIEW_H_
#define BRAVE_BROWSER_UI_VIEWS_LOCATION_BAR_BRAVE_LOCATION_BAR_WRAPPER_VIEW_H_

#include "chrome/browser/ui/views/location_bar/location_bar_view.h"
#include "chrome/browser/ui/views/toolbar/toolbar_view.h"
#include "brave/browser/ui/views/toolbar/bookmark_button.h"

class BraveLocationBarWrapperView : public views::View {
  public:
    BraveLocationBarWrapperView(Browser* browser,
                  Profile* profile,
                  CommandUpdater* command_updater,
                  ToolbarView* toolbar_view,
                  bool is_popup_mode);
    ~BraveLocationBarWrapperView() override;
    LocationBarView* location_bar() { return location_bar_; }
    void Init();
    bool IsInitialized() const;

    static const char kViewClassName[];

    // Helper to get the color for |part| using the current tint().
    SkColor GetColor(OmniboxPart part) const;

    // Returns the location bar border color blended with the toolbar color.
    // It's guaranteed to be opaque.
    SkColor GetOpaqueBorderColor(bool incognito) const;

    // Returns the color to be used for the security chip in the context of
    // |security_level|.
    SkColor GetSecurityChipColor(
        security_state::SecurityLevel security_level) const;

    // Returns the cached theme color tint for the location bar and results.
    OmniboxTint tint() const { return location_bar_->tint(); }

    // Returns the delegate.
    LocationBarView::Delegate* delegate() const { return location_bar_->delegate(); }

    // The passwords icon. It may not be visible.
    ManagePasswordsIconViews* manage_passwords_icon_view() {
      return location_bar_->manage_passwords_icon_view();
    }

    // Toggles the bookmark button on or off.
    void SetStarToggled(bool on);

    // Always return null since we have replaced the action icon
    // with a toolbar button.
    // This will ensure the bookmark bubble is anchored to
    // the location bar wrapper and not any other specific element,
    // which happens to work out since the BookmarkButton is at the
    // edge of the location bar wrapper.
    PageActionIconView* star_view() { return nullptr; }

    // The save credit card icon. It may not be visible.  It will be null when
    // |browser_| is null.
    autofill::SaveCardIconView* save_credit_card_icon_view() {
      return location_bar_->save_credit_card_icon_view();
    }

    autofill::LocalCardMigrationIconView* local_card_migration_icon_view() {
      return location_bar_->local_card_migration_icon_view();
    }

    // The translate icon. It may not be visible.
    TranslateIconView* translate_icon_view() {
      return location_bar_->translate_icon_view();
    }

    PageActionIconContainerView* page_action_icon_container_view() {
      return location_bar_->page_action_icon_container_view();
    }

    // Returns the screen coordinates of the omnibox (where the URL text appears,
    // not where the icons are shown).
    gfx::Point GetOmniboxViewOrigin() const;

    // Shows |text| as an inline autocompletion.  This is useful for IMEs, where
    // we can't show the autocompletion inside the actual OmniboxView.  See
    // comments on |ime_inline_autocomplete_view_|.
    void SetImeInlineAutocompletion(const base::string16& text);

    // Paints a custom focus ring on platforms that normally do not show focus
    // rings if |full_keyboard_accessibility_mode| is set to true.
    // TODO(tommycli): Remove this after after Material Refresh is launched.
    void SetFullKeyboardAcessibilityMode(bool full_keyboard_accessibility_mode);

    // Select all of the text. Needed when the user tabs through controls
    // in the toolbar in full keyboard accessibility mode.
    virtual void SelectAll();

    LocationIconView* location_icon_view() { return location_bar_->location_icon_view(); }

    SelectedKeywordView* selected_keyword_view() {
      return location_bar_->selected_keyword_view();
    }

    // The anchor view for security-related bubbles. That is, those anchored to
    // the leading edge of the Omnibox, under the padlock.
    views::View* GetSecurityBubbleAnchorView();

    // Show a page info dialog for |web_contents|.
    // Returns true if a dialog was shown, false otherwise.
    bool ShowPageInfoDialog(content::WebContents* web_contents);

    OmniboxViewViews* omnibox_view() {
      return location_bar_->omnibox_view();
    }
    const OmniboxViewViews* omnibox_view() const {
      return location_bar_->omnibox_view();
    }

    // Updates the controller, and, if |contents| is non-null, restores saved
    // state that the tab holds.
    void Update(const content::WebContents* contents);

    // Clears the location bar's state for |contents|.
    void ResetTabState(content::WebContents* contents);

    // Activates the first visible but inactive PageActionIconView for
    // accessibility.
    bool ActivateFirstInactiveBubbleForAccessibility();

    // LocationBar:
    void FocusLocation(bool select_all);
    void Revert() { location_bar_->Revert(); };
    OmniboxView* GetOmniboxView() {
      return location_bar_->GetOmniboxView();
    };

    // views::View:
    bool HasFocus() const override;
    void GetAccessibleNodeData(ui::AXNodeData* node_data) override;
    gfx::Size CalculatePreferredSize() const override;
    void Layout() override;
    void OnThemeChanged() override;
    void OnNativeThemeChanged(const ui::NativeTheme* theme) override;
    void ChildPreferredSizeChanged(views::View* child) override;

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

    static bool IsVirtualKeyboardVisible(views::Widget* widget);

    // Returns the height available for user-entered text in the location bar.
    static int GetAvailableTextHeight();

    // Returns the height available for text within location bar decorations.
    static int GetAvailableDecorationTextHeight();

    void OnOmniboxFocused();
    void OnOmniboxBlurred();

    // LocationBar:
    void SaveStateToContents(content::WebContents* contents) {
      location_bar_->LocationBar::SaveStateToContents(contents);
    };
    void UpdateContentSettingsIcons() {
      location_bar_->LocationBar::UpdateContentSettingsIcons();
    };

    // Extra members defined on other base classes of LocationBarView
    // that are required to be passed on:



  private:
    BookmarkButton* bookmark_button_ = nullptr;
    LocationBarView* location_bar_ = nullptr;
    DISALLOW_COPY_AND_ASSIGN(BraveLocationBarWrapperView);
};

#endif