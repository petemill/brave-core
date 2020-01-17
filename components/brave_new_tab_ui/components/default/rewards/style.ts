/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

import styled, { css } from 'brave-ui/theme'
import palette from 'brave-ui/theme/colors'
import confettiImageUrl from './confetti.png'

interface StyleProps {
  isLast?: boolean
}

interface WidgetProps {
  isEnabled: boolean
}

const Base = styled('div')`
  overflow-x: hidden;
  color: white;
  font-family: Muli, sans-serif;
  width: 284px;
`

export const WidgetWrapper = styled(Base)<WidgetProps>`
  position: relative;
  /* Show a 1x1 grid with all items overlapping.
      This makes sure that our layered notifications increase the height of the
      whole widget. Absolute positioning would not accomplish that. */
  display: grid;
  background: ${p => p.isEnabled ? palette.neutral900 : 'linear-gradient(140deg, #392DD1 0%, #8E2995 100%)'};
  border-radius: 6px;
`

export const WidgetLayer = styled(Base)`
  padding: 16px 22px 22px 22px;
  grid-row: 1 / 2;
  grid-column: 1 / 2;
`

export const Footer = styled<{}, 'div'>('div')`
  max-width: 275px;
  margin-top: 25px;
`

export const BatIcon = styled<{}, 'div'>('div')`
  width: 27px;
  height: 27px;
  margin-right: 8px;
`

export const RewardsTitle = styled<{}, 'div'>('div')`
  margin-top: 6px;
  display: flex;
  justify-content: flex-start;
  align-items: center;
  font-size: 22px;
  font-weight: 600;
  font-family: Poppins, sans-serif;
`

export const ServiceText = styled<{}, 'span'>('span')`
  color: #fff;
  font-size: 10px;
  letter-spacing: 0;
  line-height: 18px;
`

export const ServiceLink = styled<{}, 'a'>('a')`
  color: ${p => p.theme.color.brandBrave};
  font-weight: 600;
  text-decoration: none;
`

export const LearnMoreText = styled<{}, 'div'>('div')`
  font-size: 12px;
  margin-top: 34px;
`

export const PreOptInInfo = styled<{}, 'div'>('div')`
  margin-top: 14px;
`

export const Title = styled<{ isGrant?: boolean}, 'span'>('span')`
  font-size: ${p => p.isGrant ? 16 : 14}px;
  display: block;
  font-family: Poppins, sans-serif;
  line-height: 1.5;
  font-weight: 500;
`

export const SubTitle = styled<{}, 'span'>('span')`
  font-size: 14px;
  display: block;
  margin-top: 15px;
  max-width: 250px;
  line-height: 1.4;
`

export const SubTitleLink = styled<{}, 'a'>('a')`
  color: ${p => p.theme.color.brandBrave};
  text-decoration: none;
  cursor: pointer;
  &:hover {
    text-decoration: underline;
  }
`

export const PreOptInAction = styled<{}, 'div'>('div')`
  margin-top: 30px;
  text-align: center;
`

export const TurnOnButton = styled<{}, 'button'>('button')`
  border-radius: 20px;
  background: transparent;
  color: ${palette.neutral000};
  border: solid 1px ${palette.grey400};
  font-weight: 700;
  font-size: 14px;
  padding: 12px 20px;
  margin: 0 auto;
  cursor: pointer;
  word-break: break-word;
`

export const TurnOnAdsButton = styled(TurnOnButton)`
  width: 100%;
  margin-top: 8px;
  display: block;
`

export const AmountItem = styled<StyleProps, 'div'>('div')`
  margin-top: ${p => p.isLast ? 20 : 10}px;
  margin-bottom: ${p => p.isLast ? -10 : 0}px;
`

export const Amount = styled<{}, 'span'>('span')`
  font-size: 32px;
  margin-right: 10px;
  font-family: Poppins, sans-serif;
`

export const ConvertedAmount = styled<{}, 'span'>('span')`
  font-size: 14px;
`

export const AmountDescription = styled<{}, 'div'>('div')`
  font-size: 14px;
  color: #fff;
`

export const AmountUSD = styled('span')`
  margin-left: 12px;
`

export const NotificationsList = styled('div')`
  grid-row: 1 / 2;
  grid-column: 1 / 2;
  display: grid;
  margin-top: 10px;
`

const BaseNotificationWrapper = styled(WidgetLayer)<{isGrant?: boolean}>`
  background-color: ${palette.neutral800};
  ${p => p.isGrant && css`
    background-image: url(${confettiImageUrl});
    background-position: bottom center;
    background-size: contain;
    background-repeat: no-repeat;
  `}
  border-radius: 6px;
`

export const NotificationWrapper = styled(BaseNotificationWrapper)`
  /* Stack the notifications offset from each other
  and make sure they all cover the panel */
  --ntp-rewards-notification-offset: calc(var(--notification-counter, 0) * 48px);
  margin-top: var(--ntp-rewards-notification-offset);
  min-height: calc(100% - var(--ntp-rewards-notification-offset));
  width: 100%;
  box-shadow: 0px 0px 16px 0px rgba(0, 0, 0, 0.5);
`

export const OrphanedNotificationWrapper = styled(BaseNotificationWrapper)`
`

export const NotificationButton = styled(TurnOnButton)`
  background: ${palette.blurple500};
  border: solid 1px transparent;
  color: #fff;
  border: none;
  font-weight: 700;
  padding-top: 10px;
  padding-bottom: 10px;
  margin-top: 25px;
  font-size: 13px;
  :hover {
    background: ${palette.blurple600};
  }
`

export const NotificationAction = styled<{}, 'a'>('a')`
  margin-top: 20px;
  max-width: 250px;
  display: block;
  cursor: pointer;
  font-size: 14px;
  color: ${p => p.theme.color.brandBat};
  text-decoration: none;
  &:hover {
    color: ${p => p.theme.color.brandBat};
    text-decoration: underline;
  }
`

export const CloseIcon = styled<{}, 'div'>('div')`
  color: #fff;
  width: 13px;
  height: 13px;
  float: right;
  cursor: pointer;
  margin-top: 2px;
`

export const UnsupportedMessage = styled<{}, 'div'>('div')`
  color: rgba(255, 255, 255, 0.70);
  font-size: 14px;
  max-width: 235px;
  margin-top: 8px;
`
