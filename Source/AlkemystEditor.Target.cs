// Showcase project of Lana Medved and Emin Turalic

using UnrealBuildTool;
using System.Collections.Generic;

public class AlkemystEditorTarget : TargetRules
{
	public AlkemystEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Alkemyst" } );
	}
}
