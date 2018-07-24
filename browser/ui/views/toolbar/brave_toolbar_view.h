/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_UI_VIEWS_TOOLBAR_BRAVE_TOOLBAR_VIEW_H_
#define BRAVE_BROWSER_UI_VIEWS_TOOLBAR_BRAVE_TOOLBAR_VIEW_H_

#include "chrome/browser/ui/views/toolbar/toolbar_view.h"

class BraveToolbarView : public ToolbarView {
  public:
    using ToolbarView::ToolbarView;
    void ShowBookmarkBubble(const GURL& url,
                            bool already_bookmarked,
                            bookmarks::BookmarkBubbleObserver* observer) override;
  private:
    DISALLOW_COPY_AND_ASSIGN(BraveToolbarView);
};

#endif