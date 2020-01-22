/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

import styled from 'brave-ui/theme'
// import { StyledStatsItemContainer } from '../stats/style'

export const Header = styled<{}, 'header'>('header')`
  display: contents;

  @media screen and (max-width: 1150px) {
    grid-row-gap: 4px;
    grid-template-areas:
    "clock clock clock"
    "stats stats stats"
    "topsites topsites topsites"
    "rewards rewards rewards"
    "notification notification notification";


    > *:nth-child(1) {
      margin: auto;
      text-align: center;
    }

    > *:nth-child(2) {
      margin: auto;
      text-align: center;
    }

    > *:nth-child(3) {
      margin: auto;
      justify-content: center;
    }

    > *:nth-child(4) {
      margin: auto;
      justify-content: center;
    }
  }
`
export const Main = styled<{}, 'main'>('main')`
  box-sizing: border-box;
`

export const Footer = styled<{}, 'footer'>('footer')`
  display: contents;
  /* display: grid;
  align-items: center;
  grid-template-columns: 1fr auto;
  grid-template-rows: auto;
  grid-gap: 0;
  grid-template-areas: "credits actions"; */
  /* Extra margin since there is no widget box padding */
  margin: 0 12px 12px 12px;

    > .credit {
      grid-area: credits;
    }

    > .navigation {
      grid-area: actions;
    }

  @media screen and (max-width: 1150px) {

    > *:nth-child(2) {
      justify-content: flex-end;
    }
  }

  @media screen and (max-width: 390px) {
    grid-template-areas:
      "credits"
      "actions";

      > *:first-child {
        text-align: center;
      }

      > *:nth-child(2) {
        justify-content: center;
      }
  }
`
