/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */
#pragma once

#include <com/sun/star/uno/Reference.h>
#include <rtl/ref.hxx>
#include <rtl/ustring.hxx>
#include "charttoolsdllapi.hxx"

namespace chart { class ChartModel; }
namespace chart { class ReferenceSizeProvider; }
namespace com::sun::star::chart2 { class XTitle; }
namespace com::sun::star::frame { class XModel; }
namespace com::sun::star::uno { class XComponentContext; }

namespace chart
{

class OOO_DLLPUBLIC_CHARTTOOLS TitleHelper
{
public:
    enum eTitleType
    {
        TITLE_BEGIN = 0,
        MAIN_TITLE = 0,
        SUB_TITLE,
        X_AXIS_TITLE,
        Y_AXIS_TITLE,
        Z_AXIS_TITLE,
        SECONDARY_X_AXIS_TITLE,
        SECONDARY_Y_AXIS_TITLE,
        NORMAL_TITLE_END,

        //it is intended that this both types are after NORMAL_TITLE_END
        TITLE_AT_STANDARD_X_AXIS_POSITION, //equals the Y_AXIS_TITLE for barchart
        TITLE_AT_STANDARD_Y_AXIS_POSITION  //equals the X_AXIS_TITLE for barchart
    };

    static css::uno::Reference< css::chart2::XTitle >
        getTitle( eTitleType nTitleIndex
                    , ChartModel& rModel );

    static css::uno::Reference< css::chart2::XTitle >
        getTitle( eTitleType nTitleIndex
                    , const rtl::Reference< ::chart::ChartModel >& xModel );

    static css::uno::Reference<
            css::chart2::XTitle >
        createTitle(  eTitleType nTitleIndex
                    , const OUString& rTitleText
                    , const rtl::Reference< ::chart::ChartModel >& xModel
                    , const css::uno::Reference< css::uno::XComponentContext > & xContext
                    , ReferenceSizeProvider * pRefSizeProvider = nullptr );
    static css::uno::Reference<
            css::chart2::XTitle >
          createOrShowTitle(  eTitleType nTitleIndex
                    , const OUString& rTitleText
                    , const rtl::Reference< ::chart::ChartModel >& xModel
                    , const css::uno::Reference< css::uno::XComponentContext > & xContex );

    static void removeTitle( eTitleType nTitleIndex
                    , const rtl::Reference< ::chart::ChartModel >& xModel );

    static OUString getCompleteString( const css::uno::Reference< css::chart2::XTitle >& xTitle );
    static void setCompleteString( const OUString& rNewText
        , const css::uno::Reference< css::chart2::XTitle >& xTitle
        , const css::uno::Reference< css::uno::XComponentContext > & xContext
        , const float * pDefaultCharHeight = nullptr );

    static bool getTitleType( eTitleType& rType
                    , const css::uno::Reference< css::chart2::XTitle >& xTitle
                    , ChartModel& rModel);

    static bool getTitleType( eTitleType& rType
                    , const css::uno::Reference< css::chart2::XTitle >& xTitle
                    , const rtl::Reference< ::chart::ChartModel >& xModel );
    static void hideTitle( eTitleType nTitleIndex,
            const rtl::Reference< ::chart::ChartModel > & xModel);
};

} //namespace chart

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
