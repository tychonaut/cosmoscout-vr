////////////////////////////////////////////////////////////////////////////////////////////////////
//                               This file is part of CosmoScout VR                               //
//      and may be used under the terms of the MIT license. See the LICENSE file for details.     //
//                        Copyright: (c) 2019 German Aerospace Center (DLR)                       //
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "DisplayHandler.hpp"

#include "../logger.hpp"

namespace cs::gui::detail {

////////////////////////////////////////////////////////////////////////////////////////////////////

bool DisplayHandler::OnConsoleMessage(CefRefPtr<CefBrowser> /*browser*/, cef_log_severity_t level,
    CefString const& message, CefString const& /*source*/, int /*line*/) {

  if (level == LOGSEVERITY_VERBOSE) {
    logger().trace(message.ToString());
  } else if (level == LOGSEVERITY_DEBUG) {
    logger().debug(message.ToString());
  } else if (level == LOGSEVERITY_WARNING) {
    logger().warn(message.ToString());
  } else if (level == LOGSEVERITY_ERROR) {
    logger().error(message.ToString());
  } else if (level == LOGSEVERITY_FATAL) {
    logger().critical(message.ToString());
  } else {
    logger().info(message.ToString());
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace cs::gui::detail
