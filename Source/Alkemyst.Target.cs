// Showcase project of Lana Medved and Emin Turalic

using UnrealBuildTool;
using System.Collections.Generic;

public class AlkemystTarget : TargetRules
{
	public AlkemystTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Alkemyst" } );
	}
}
