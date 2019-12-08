// Copyright(c) 2019 Daniel Marshall
// SPDX-License-Identifier: MIT

using UnrealBuildTool;
using System.Collections.Generic;

public class EscapeEditorTarget : TargetRules
{
	public EscapeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Escape" } );
	}
}
