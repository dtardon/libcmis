/* libcmis
 * Version: MPL 1.1 / GPLv2+ / LGPLv2+
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License or as specified alternatively below. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * Major Contributor(s):
 * Copyright (C) 2011 SUSE <cbosdonnat@suse.com>
 *
 *
 * All Rights Reserved.
 *
 * For minor contributions see the git repository.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPLv2+"), or
 * the GNU Lesser General Public License Version 2 or later (the "LGPLv2+"),
 * in which case the provisions of the GPLv2+ or the LGPLv2+ are applicable
 * instead of those above.
 */

#include "allowable-actions.h"
#include "internals.hxx"

void libcmis_allowable_actions_free( libcmis_AllowableActionsPtr allowable )
{
    delete allowable;
}


bool libcmis_allowable_actions_isAllowed( libcmis_AllowableActionsPtr allowable,
        libcmis_allowable_actions_Type action )
{
    bool result = false;
    if ( allowable != NULL && allowable->handle.get( ) != NULL )
        result = allowable->handle->isAllowed( libcmis::ObjectAction::Type( action ) );
    return result;
}


bool libcmis_allowable_actions_isDefined( libcmis_AllowableActionsPtr allowable,
        libcmis_allowable_actions_Type action )
{
    bool result = false;
    if ( allowable != NULL && allowable->handle.get( ) != NULL )
        result = allowable->handle->isDefined( libcmis::ObjectAction::Type( action ) );
    return result;
}