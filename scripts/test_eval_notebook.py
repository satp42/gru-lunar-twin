#!/usr/bin/env python3

import os
import sys

def test_eval_notebook():
    """Test Task 24 acceptance criteria"""
    print("=== Task 24 Eval Notebook Test ===")
    
    # Check notebook exists
    notebook_path = 'rl/eval/reward.ipynb'
    if os.path.exists(notebook_path):
        print("✅ Notebook exists: rl/eval/reward.ipynb")
    else:
        print("❌ Notebook not found")
        return False
    
    # Check screenshot exists
    screenshot_path = 'rl/eval/fleet_reward_evaluation.png'
    if os.path.exists(screenshot_path):
        size = os.path.getsize(screenshot_path)
        print(f"✅ Screenshot exists: {screenshot_path} ({size} bytes)")
        
        if size > 0:
            print("✅ Screenshot has content (size > 0)")
        else:
            print("❌ Screenshot is empty")
            return False
    else:
        print("❌ Screenshot not found")
        return False
    
    # Check if it contains the expected content
    try:
        with open(notebook_path, 'r') as f:
            content = f.read()
            if 'plt.figure' in content and 'plt.plot' in content:
                print("✅ Notebook contains plotting code")
            else:
                print("❌ Notebook missing plotting code")
                return False
                
            if 'fleet_reward_evaluation.png' in content:
                print("✅ Notebook saves screenshot")
            else:
                print("❌ Notebook doesn't save screenshot")
                return False
                
    except Exception as e:
        print(f"❌ Error reading notebook: {e}")
        return False
    
    print("✅ Task 24 COMPLETE: none → curve plotted → screenshot added to repo")
    return True

if __name__ == "__main__":
    success = test_eval_notebook()
    sys.exit(0 if success else 1) 