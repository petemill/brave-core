/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/ui/views/frame/brave_browser_view.h"
#include "chrome/browser/ui/views/toolbar/toolbar_view.h"
#include "brave/browser/ui/views/toolbar/bookmark_button.h"

ToolbarView::ShowBookmarkBubble(
    const GURL& url,
    bool already_bookmarked,
    bookmarks::BookmarkBubbleObserver* observer) {
  views::View* anchor_view = location_bar();

  BookmarkButton* const star_view = location_bar()->star_view();

  // Show BookmarkBubble attached to Brave's bookmark button
  std::unique_ptr<BubbleSyncPromoDelegate> delegate;
  delegate.reset(new BookmarkBubbleSignInDelegate(browser_));
  views::Widget* bubble_widget = BookmarkBubbleView::ShowBubble(
      star_view, gfx::Rect(), nullptr, observer, std::move(delegate),
      browser_->profile(), url, already_bookmarked);
  if (bubble_widget && star_view)
    star_view->OnBubbleWidgetCreated(bubble_widget);
}